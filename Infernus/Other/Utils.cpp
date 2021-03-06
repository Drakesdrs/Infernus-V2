#include "Utils.h"
#include "../SDK/Minecraft.h"

HMODULE Utils::hModule = nullptr;

bool Utils::hasExtension(const std::string& fileName) {
	std::string::size_type idx;
	idx = fileName.rfind('.');

	return idx != std::string::npos;
}

bool Utils::doesPathExist(const std::string& path) {
	struct stat buffer{};
	return (stat(path.c_str(), &buffer) == 0);
}

void Utils::CreateDir(const std::string& path) {
	if (!hasExtension(path)) {
		std::string envPath = getenv("APPDATA");
		if (envPath.length() <= 0)
			return;

		std::string roamingDir = envPath + std::string(R"(\..\Local\Packages\Microsoft.MinecraftUWP_8wekyb3d8bbwe\RoamingState\)");
		if (!doesPathExist(roamingDir))
			return;

		std::string precisePath = std::string(roamingDir + path);
		std::filesystem::create_directories(precisePath);
	}
}

void Utils::DeletePath(std::string path) {
	std::string precisePath = getenv("APPDATA") + std::string(R"(\..\Local\Packages\Microsoft.MinecraftUWP_8wekyb3d8bbwe\RoamingState\)" + path);
	if (doesPathExist(precisePath)) {
		if (std::filesystem::is_directory(precisePath)) {
			std::filesystem::remove_all(precisePath);
		}
		else {
			std::filesystem::remove(precisePath);
		}
	}
}

void Utils::WriteToFile(const std::string& str, const std::string& path) {
	if (hasExtension(path)) {
		std::string precisePath = getenv("APPDATA") + std::string(R"(\..\Local\Packages\Microsoft.MinecraftUWP_8wekyb3d8bbwe\RoamingState\)" + path);
		if (!doesPathExist(precisePath)) {
			std::filesystem::path p(precisePath);
			std::filesystem::create_directories(p.parent_path().string());
		}

		CloseHandle(CreateFileA(precisePath.c_str(), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, nullptr));
		if (doesPathExist(precisePath) && str.length() > 0) {
			std::ofstream fileOutput;
			fileOutput.open(precisePath.c_str(), std::ios_base::app);
			fileOutput << str << std::endl;
			fileOutput.close();
		}
	}
}

void Utils::DebugLogOutput(const std::string& str) {
	WriteToFile(str, "Infernus/Output.txt");
}

uintptr_t Utils::FindAddr(uintptr_t ptrBase, const std::vector<unsigned int>& offsets) {
	uintptr_t curr = NULL;
	if (ptrBase != NULL) {
		curr = ptrBase;
		for (unsigned int offset : offsets) {
			curr = *(uintptr_t*)(curr += offset);
			if (curr == NULL) {
				break;
			}
		}
	}
	return curr;
}

uintptr_t Utils::FindSig(const char* szSignature) {
	const char* pattern = szSignature;
	uintptr_t firstMatch = 0;
	static const auto rangeStart = (uintptr_t)GetModuleHandleA("Minecraft.Windows.exe");
	static MODULEINFO miModInfo;
	static bool init = false;
	if (!init) {
		init = true;
		GetModuleInformation(GetCurrentProcess(), (HMODULE)rangeStart, &miModInfo, sizeof(MODULEINFO));
	}
	static const uintptr_t rangeEnd = rangeStart + miModInfo.SizeOfImage;

	BYTE patByte = GET_BYTE(pattern);
	const char* oldPat = pattern;

	for (uintptr_t pCur = rangeStart; pCur < rangeEnd; pCur++)
	{
		if (!*pattern)
			return firstMatch;

		while (*(PBYTE)pattern == ' ')
			pattern++;

		if (!*pattern)
			return firstMatch;

		if (oldPat != pattern) {
			oldPat = pattern;
			if (*(PBYTE)pattern != '\?')
				patByte = GET_BYTE(pattern);
		}

		if (*(PBYTE)pattern == '\?' || *(BYTE*)pCur == patByte)
		{
			if (!firstMatch)
				firstMatch = pCur;

			if (!pattern[2])
				return firstMatch;

			pattern += 2;
		}
		else
		{
			pattern = szSignature;
			firstMatch = 0;
		}
	}
	return 0;
}

std::string Utils::ptrToStr(uintptr_t ptr) {
	std::ostringstream ss;
	ss << std::hex << ((UINT64)ptr) << std::endl;
	return ss.str();
}

uint64_t Utils::strToPtr(const std::string& ptr) {
	std::stringstream ss(ptr);
	uint64_t result;
	ss >> result;
	return result;
}

bool Utils::isStringFloat(const std::string& str) {
	std::istringstream iss(str);
	float f;
	iss >> std::noskipws >> f;
	return iss.eof() && !iss.fail();
};

float Utils::randomFloat(int min, int max) {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<>dis(min, max);
	return dis(gen);
}

bool Utils::stringToBool(const std::string& str) {
	bool b;
	std::istringstream(str) >> std::boolalpha >> b;
	return b;
}

std::map<uint64_t, bool> Utils::KeyMapping;

bool Utils::usingKey(uint64_t key) {
	return KeyMapping[key];
}

bool Utils::IsInit(Vec2 MousePos, Vec4 Rectangle) {
	if (MousePos.x >= Rectangle.x && MousePos.x <= Rectangle.z && MousePos.y >= Rectangle.y && MousePos.y <= Rectangle.w)
		return true;
	else
		return false;
}

//int Utils::GMVelocityPriority = 0;
//
//void Utils::SetGMVelocity(Vec3 velocity, int Priority) {
//	if (GMVelocityPriority <= Priority && Minecraft().ClientInstance()->LocalPlayer() != nullptr) {
//		GMVelocityPriority = Priority;
//		Minecraft().ClientInstance()->LocalPlayer()->velocity = velocity;
//	}
//}

//
//void Utils::setentity(Actor &nigga) {
//	bool yes = true;
//	for (int i = 0; i < entidies.size(); i++) {
//		if (&entidies.at(i) == &nigga && nigga.isAlive()) { yes = false; break; };
//	}
//	if (yes && (nigga.getPos() != nigga.getPosOld())) {
//		entidies.push_back(nigga);
//	}
//}
//
//bool Utils::getentity(Actor& nigga) {
//	for (int i = 0; i < entidies.size(); i++) {
//		if (&entidies.at(i) == &nigga) { return true; break; };
//	}
//	return false;
//}


Vec2 Utils::getAngles(Vec3 PlayerPosition, Vec3 EntityPosition) {
	Vec2 Angles;
	float dX = PlayerPosition.x - EntityPosition.x;
	float dY = PlayerPosition.y - EntityPosition.y;
	float dZ = PlayerPosition.z - EntityPosition.z;
	double distance = sqrt(dX * dX + dY * dY + dZ * dZ);
	Angles.x = (float)(atan2(dY, distance) * 180.0f / PI);
	Angles.y = (float)(atan2(dZ, dX) * 180.0f / PI) + 90.0f;
	return Angles;
};

/* Render Utils */

#include "../SDK/Classes/ClientInstance.h"

class MinecraftUIRenderContext* RenderUtils::CachedContext = nullptr; //Resolve Compile Error
class BitmapFont* RenderUtils::CachedFont = nullptr;

void RenderUtils::SetContext(class MinecraftUIRenderContext* Context, class BitmapFont* Font) {
	CachedContext = Context;
	CachedFont = Font;
}

void RenderUtils::FlushText() {
	if (CachedContext != nullptr) CachedContext->flushText(0);
}

float RenderUtils::GetTextWidth(std::string text, float textSize) {
	if (CachedContext != nullptr) {
		TextHolder myText(std::move(text));
		return CachedContext->getLineLength(CachedFont, &myText, textSize, false);
	}
	return 0;
}

void RenderUtils::RenderText(std::string text, Vec2 textPos, const MC_Colour& colour, float textSize, float alpha) {
	if (CachedContext != nullptr && CachedFont != nullptr) {
		static uintptr_t caretMeasureData = 0xFFFFFFFF;
		Vec4 pos(textPos.x, textPos.x + 100, textPos.y, textPos.y + 100);
		TextHolder myText(std::move(text));
		CachedContext->drawText(CachedFont, &pos, &myText, colour, alpha, 0, &textSize, &caretMeasureData);
	}
}

void RenderUtils::FillRectangle(Vec4 position, const MC_Colour& colour, float alpha) {
	if (CachedContext != nullptr) {
		CachedContext->fillRectangle(Vec4(position.x, position.z, position.y, position.w), colour, alpha);
	}
}

void RenderUtils::DrawRectangle(Vec4 position, const MC_Colour& colour, float alpha, float lineWidth) {
	if (CachedContext != nullptr) {
		lineWidth /= 2;
		FillRectangle(Vec4(position.x - lineWidth, position.y - lineWidth, position.z + lineWidth, position.y + lineWidth), colour, alpha);
		FillRectangle(Vec4(position.x - lineWidth, position.y, position.x + lineWidth, position.w), colour, alpha);
		FillRectangle(Vec4(position.z - lineWidth, position.y, position.z + lineWidth, position.w), colour, alpha);
		FillRectangle(Vec4(position.x - lineWidth, position.w - lineWidth, position.z + lineWidth, position.w + lineWidth), colour, alpha);
	}
}
