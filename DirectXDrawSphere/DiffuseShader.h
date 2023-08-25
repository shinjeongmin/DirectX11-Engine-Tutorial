#pragma once

#include "VertexShader.h"
#include "PixelShader.h"

#include <string>

// Wrapping ���δ� �ڵ�.
// ���� (Wrapper).
class DiffuseShader
{
public:
	// ������ / ���� �ѹ���. ���� �Լ�.
	bool Initialize(ID3D11Device* device, std::wstring textureFileName);

	bool Compile(ID3D11Device* device, std::wstring textureFileName);
	bool Create(ID3D11Device* device);
	void Bind(ID3D11DeviceContext* deviceContext);

	ID3DBlob* ShaderBuffer();

private:
	VertexShader vertexShader;
	PixelShader pixelShader;
};