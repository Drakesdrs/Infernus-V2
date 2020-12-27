#pragma once

class MultiPlayerLevel {
public:
	char pad_0008[72]; //0x0008
	uint64_t listStart; //0x0050
	uint64_t listEnd; //0x0058
	char pad_0060[2264]; //0x0060
	uint32_t facingFlag; //0x0938
	uint32_t blockFace; //0x093C
	Vec3_i facingBlockPos; //0x0940
	char pad_094C[12]; //0x094C
	class Actor* facingActor; //0x0958

	/* VTable Functions (Not currently defined) */

	virtual void Function0();
	virtual void Function1();
	virtual void Function2();
	virtual void Function3();
	virtual void Function4();
	virtual void Function5();
	virtual void Function6();
	virtual void Function7();
	virtual void Function8();
	virtual void Function9();
public:

	inline class Actor* get(size_t idx) {
		if (idx >= getListSize())
			return 0;
		return *reinterpret_cast<class Actor**>(listStart + (idx * sizeof(uintptr_t)));
	};
	inline size_t getListSize() {
		return (listEnd - listStart) / sizeof(uintptr_t);
	};
};