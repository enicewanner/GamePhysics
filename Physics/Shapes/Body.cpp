#include "Body.h"
#include "../../Engine/Integrator.h"
#include "../../Engine/World.h"
#include "CircleShape.h"

void Body::Step(float dt)
{
	if (type != DYNAMIC) return;

	//gravity
	ApplyForce(World::gravity * gravityScale * mass);

	Integrator::SemiImplicitEuler(*this, dt);
	ClearForce();
	velocity = velocity * 1.0f / (1.0f + (dt * damping));
}

void Body::Draw(Graphics* m_graphics)
{
	shape->Draw(m_graphics, position);
}
void Body::ApplyForce(const glm::vec2& force)
{
	this->force += force;
}

bool Body::Intersects(Body* body)
{
	glm::vec2 direction = (position - body->position);
	float distance = glm::length(direction);
	float radius = dynamic_cast<CircleShape*>(shape)->radius + dynamic_cast<CircleShape*>(body->shape)->radius;

	return false;
}