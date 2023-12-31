#pragma once
#pragma once

#include "Vertex.h"
#include <d3d11.h>
#include <wrl.h>
#include "TransformBuffer.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "InputLayout.h"

using Microsoft::WRL::ComPtr;

class Mesh
{
public:
	Mesh();
	~Mesh();

	virtual bool InitializeBuffers(ID3D11Device* device, ID3DBlob* vertexShaderBuffer) = 0;
	// Render = (Bind + Draw)
	virtual void RenderBuffers(ID3D11DeviceContext* deviceContext);

	// 드로우/업데이트 관련 편의 함수.
	virtual void BindBuffers(ID3D11DeviceContext* deviceContext);
	virtual void DrawBuffers(ID3D11DeviceContext* deviceContext);

	virtual void UpdateBuffers(ID3D11DeviceContext* deviceContext);

	// Getter / Setter
	Vector3f& Position() { return position; }
	void SetPosition(float x, float y, float z);
	void SetPosition(Vector3f position);

	Vector3f& Rotation() { return rotation; }
	void SetRotation(float x, float y, float z);
	void SetRotation(Vector3f rotation);

	Vector3f& Scale() { return scale; }
	void SetScale(float x, float y, float z);
	void SetScale(Vector3f scale);

protected:
	//int vertexCount;				// 정점 개수.
	//int indexCount;					// 인덱스 개수.
	//ComPtr<ID3D11Buffer> vertexBuffer;		// 정점 버퍼.
	//ComPtr<ID3D11Buffer> indexBuffer;		// 인덱스 버퍼.

	//ComPtr<ID3D11InputLayout> inputLayout; // 입력 레이아웃.
	VertexBuffer vertexBuffer;
	IndexBuffer indexBuffer;
	InputLayout inputLayout;


	// 트랜스폼 버퍼.
	TransformBuffer transform;

	// 트랜스폼 데이터.
	Vector3f position;
	Vector3f rotation;
	Vector3f scale;
};