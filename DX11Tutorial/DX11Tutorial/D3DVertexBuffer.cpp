#include "D3DVertexBuffer.h"
#include "SystemClass.h"

D3DVertexBuffer::D3DVertexBuffer(void):
							m_buffer(NULL),
							m_memsize(0)
					
{

}

D3DVertexBuffer::~D3DVertexBuffer(void)
{
	fini();
}

ID3D11Buffer* D3DVertexBuffer::buffer()
{
	return m_buffer;
}

bool D3DVertexBuffer::init( unsigned int memsize, void* memory )
{
	D3D11_BUFFER_DESC vertexBufferDesc;
	D3D11_SUBRESOURCE_DATA vertexData;

	vertexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	vertexBufferDesc.ByteWidth = memsize;
	vertexBufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	vertexBufferDesc.CPUAccessFlags = 0;
	vertexBufferDesc.MiscFlags = 0;
	vertexBufferDesc.StructureByteStride = 0;

	vertexData.pSysMem = memory;
	vertexData.SysMemPitch = 0;
	vertexData.SysMemSlicePitch = 0;

	HRESULT result = SystemClass::Instance().renderModul()->GetDevice()->CreateBuffer(&vertexBufferDesc, &vertexData, &m_buffer);
	if(FAILED(result))
	{
		return false;
	}
	m_memsize = memsize;
	return true;
}

void D3DVertexBuffer::fini()
{
	if(NULL != m_buffer)
	{
		m_buffer->Release();
		m_buffer = NULL;
	}
	m_memsize = 0;

}