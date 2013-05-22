#ifndef D3DVERTEXBUFFER_H_
#define D3DVERTEXBUFFER_H_

#include "d3dclass.h"
class D3DVertexBuffer
{
public:
	D3DVertexBuffer();
	~D3DVertexBuffer(void);
	
public:
	ID3D11Buffer* buffer() ;

	bool init(unsigned int memsize, void* memory);
	
private:
	void fini();
private:
	ID3D11Buffer* m_buffer; 

	unsigned int m_memsize;
};
#endif//D3DVERTEXBUFFER_H_