#include "ForceTest.h"
#include "../Physics/Shapes/Body.h"
#include "../Physics/Shapes/CircleShape.h"
#include "../Physics/Forces/GravitationalGenerator.h"
#include "../Physics/Forces/DragForce.h"
#include "../Physics/Forces/AreaForce.h"
#include "../Physics/Forces/PointForce.h"


#define POINT_FORCE
//#define AREA_FORCE
//#define DRAG_FORCE


void ForceTest::Initialize()
{
	Test::Initialize();

	//auto forceGenerator = new GravitationalGenerator(0);
	//m_world->AddForceGenerator(forceGenerator);


#if defined(POINT_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new PointForce(body, 2000);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(AREA_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new AreaForce(body, 2000, -90);
	m_world->AddForceGenerator(forceGenerator);
#elif defined(DRAG_FORCE)
	auto body = new Body(new CircleShape(200, { 1, 1, 1, 0.2f }), { 400, 300 }, { 0, 0 }, 0, Body::STATIC)
		;
	ForceGenerator* forceGenerator = new DragForce(body, 0.5f);
	m_world->AddForceGenerator(forceGenerator);
#endif

}

//void ForceTest::Run()
//{
//	UpdateEvents();
//
//	m_input->Update();
//	m_time->Update();
//
//
//
//
//	m_graphics->SetColor({ 0, 0, 0, 1 });
//	m_graphics->Clear();
//
//
//
//	m_graphics->Present();
//}

void ForceTest::Update()
{
	Test::Update();

	glm::vec2 position = m_graphics->ScreenToWorld(m_input->GetMousePosition());

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(10, 20);

		float size = randomf(1, 8);
		auto body = new Body(new CircleShape((size * 3), { randomf(), randomf(), randomf(), 1 }), position, velocity, size);
		body->gravityScale = 30;
		m_world->AddBody(body);

	}
}

void ForceTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());

}

void ForceTest::Render()
{
	m_graphics->DrawCircle(m_graphics->ScreenToWorld(m_input->GetMousePosition()), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
