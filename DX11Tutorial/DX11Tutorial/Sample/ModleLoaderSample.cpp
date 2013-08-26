#include "ModleLoaderSample.h"
#include "REsMrg/ModleLoader.h"

ModleLoaderSample::ModleLoaderSample(void)
{
}

ModleLoaderSample::~ModleLoaderSample(void)
{
}

bool ModleLoaderSample::init()
{

	Model* pModel = ModleLoader::Instance().loaderModel(L"../res/modle/cube.obj",&m_vertexBuffer, &m_indexBuffer);
	
	return pModel == NULL;
}

void ModleLoaderSample::fini()
{

}

void ModleLoaderSample::update( float det )
{

}

bool ModleLoaderSample::render()
{
	return true;
}