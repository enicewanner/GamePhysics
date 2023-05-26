#pragma once
#include "Test.h"

class ParticleTest : public Test
{
public:
	void Initialize() override;
	//void Run() override;

	void Update();

protected:


	// Inherited via Test
	virtual void FixedUpdate() override;

	virtual void Render() override;

};