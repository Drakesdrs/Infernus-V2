#include "Velocity.h"

void Velocity::onLerp(Actor* Entity, Vec3* Velocity) {
	Velocity->x *= newVel.x;
	Velocity->y *= newVel.y;
	Velocity->z *= newVel.z;
}