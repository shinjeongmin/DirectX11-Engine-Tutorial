#pragma once
#include "D3DApp.h"
#include "VertexShader.h"
#include "PixelShader.h"
#include "Mesh.h"
#include "Triangle.h"
#include "Quad.h"

#include "Matrix4f.h"
#include <wrl.h>

using Microsoft::WRL::ComPtr;

class Engine : public D3DApp
{
public:
	Engine(HINSTANCE hInstance, int width, int height, std::wstring title);
	~Engine();

	bool Initialize() override; // 타이머, 씬 등에 대한 초기화
	int Run() override;

protected:
	void Update() override;
	void DrawScene() override;
	
private:
	// 장면 초기화.
	bool InitializeScene();

	Quad quad;
	Triangle triangle;
};

