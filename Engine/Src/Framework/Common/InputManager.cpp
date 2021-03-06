#include "pch.h"
#include "Framework/Common/InputManager.h"
#include "Framework/Common/GraphicsManager.h"
#include "Framework/Common/Log.h"

int Engine::InputManager::Initialize()
{
	int ret = 0;
	//thread_input_handler_ = std::move(std::thread(&InputManager::ProcessInput,this,&cur_mouse_ev_));
	//thread_input_handler_.detach();
	return ret;
}

void Engine::InputManager::Finalize()
{

}

void Engine::InputManager::Tick()
{
}

void Engine::InputManager::ButtonDown(EKeyButton btn)
{
	if(btn == EKeyButton::kD)
	{
		g_pGraphicsManager->MoveCameraRight(200.f);
	}
	else if (btn == EKeyButton::kA)
	{
		g_pGraphicsManager->MoveCameraRight(-200.f);
	}
	else if(btn == EKeyButton::kW)
	{
		g_pGraphicsManager->MoveCameraForward(200.f);
	}
	else if (btn == EKeyButton::kS)
	{
		g_pGraphicsManager->MoveCameraForward(-200.f);
	}
	else if (btn == EKeyButton::kArrowLeft)
	{
#ifdef _DEBUG
		NE_LOG(ALL,kNormal,"ArrowLeft key down")
#endif // _DEBUG
		g_pGameLogic->OnLeftKeyDown();
	}
}

void Engine::InputManager::ButtonUp(EKeyButton btn)
{

}

void Engine::InputManager::MouseMove(const MouseMoveEvent& ev)
{
	float dx = static_cast<float>(ev.x_ - pre_mouse_pos[0]) * 0.25f;
	float dy = static_cast<float>(ev.y_ - pre_mouse_pos[1]) * 0.25f;
	g_pGraphicsManager->CameraRotateYaw(dx);
	g_pGraphicsManager->CameraRotatePitch(dy);
	pre_mouse_pos[0] = ev.x_;
	pre_mouse_pos[1] = ev.y_;
	cur_mouse_ev_.x_ = ev.x_;
	cur_mouse_ev_.y_ = ev.x_;
}

void Engine::InputManager::SetPreMousePos(int x, int y)
{
	pre_mouse_pos[0] = static_cast<int32_t>(x);
	pre_mouse_pos[1] = static_cast<int32_t>(y);
}


void Engine::InputManager::ProcessInput(MouseMoveEvent* ev)
{
	while (true)
	{
		float dx = static_cast<float>(ev->x_ - pre_mouse_pos[0]) * 0.25f;
		float dy = static_cast<float>(ev->y_ - pre_mouse_pos[1]) * 0.25f;
		g_pGraphicsManager->CameraRotateYaw(dx);
		pre_mouse_pos[0] = ev->x_;
		pre_mouse_pos[1] = ev->y_;
	}
}


