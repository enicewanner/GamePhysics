#include "JointTest.h"
#include "../Physics/Shapes/CircleShape.h"
#include "../Physics/Shapes/Body.h"
#include "../Physics/Constraints/Joint.h"

#define SPRING_STIFFNESS 50
#define SPRING_LENGTH 1
#define BODY_DAMPING 10
#define CHAIN_SIZE 3
#define GRID_SIZE 3

void JointTest::Initialize()
{
	Test::Initialize();

	m_anchor = new Body(new CircleShape(1, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 0, Body::KINEMATIC);
	m_world->AddBody(m_anchor);

	auto prevBody = m_anchor;

	//chain -> for loop
	for (int i = 0; i < CHAIN_SIZE; i++)
	{

		auto body = new Body(new CircleShape(0.5, { 1, 1, 1, 1 }), { 0, 0 }, { 0, 0 }, 1, Body::DYNAMIC);
		body->damping = BODY_DAMPING;
		m_world->AddBody(body);

		auto joint = new Joint(prevBody, body, SPRING_STIFFNESS, SPRING_LENGTH);
		m_world->AddJoint(joint);

		prevBody = body;

	}

	//grid -> for loop
	for (int i = 0; i < GRID_SIZE; i++)
	{
		auto bodyA = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		auto bodyB = new Body(new CircleShape(20, { 1, 1, 1, 1 }), { 400, 200 }, { 0, 0 }, 1, Body::DYNAMIC);
		m_world->AddBody(bodyA);
		m_world->AddBody(bodyB);

		//auto jointA

	}

}

void JointTest::Update()
{
	Test::Update();
	m_anchor->position = m_graphics->ScreenToWorld(m_input->GetMousePosition());
}

void JointTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());
}

void JointTest::Render()
{
	m_world->Draw(m_graphics);
	m_graphics->DrawCircle(m_input->GetMousePosition(), 10, { randomf(), randomf(), randomf(), 1 });
}
