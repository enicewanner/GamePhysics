#include "ParticleTest.h"
#include "../Physics/Shapes/Body.h"
#include "../Physics/Shapes/CircleShape.h"

void ParticleTest::Initialize()
{
	Test::Initialize();
}

//void ParticleTest::Run()
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

void ParticleTest::Update()
{
	Test::Update();

	if (m_input->GetMouseButton(0))
	{
		glm::vec2 velocity = randomUnitCircle() * randomf(100, 200);
		auto body = new Body(new CircleShape(randomf(0, 100), { randomf(), randomf(), randomf(), 1 }), (m_input->GetMousePosition(), velocity));
		body->damping = 1;
		m_world->AddBody(body);

	}
}

void ParticleTest::FixedUpdate()
{
	m_world->Step(m_time->GetFixedDeltaTime());

}

void ParticleTest::Render()
{
	m_graphics->DrawCircle(m_graphics->ScreenToWorld(m_input->GetMousePosition()), 30, { randomf(), randomf(), randomf(), 1 });
	m_world->Draw(m_graphics);
}
