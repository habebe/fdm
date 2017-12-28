#include "ModelGeometryLoader.hxx"
#include "ModelGeometry.hxx"
#include <iostream>
#include <assimp/Importer.hpp>    
#include <assimp/scene.h> 
#include <assimp/postprocess.h> 
ModelGeometryLoader * ModelGeometryLoader::s_instance = nullptr;


ModelGeometry* ModelGeometryLoader::load(const char* path) {
	const aiScene* scene = m_importer.ReadFile(path,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType);
	ModelGeometry* model = new ModelGeometry(scene);
	return model;
}

ModelGeometryLoader * ModelGeometryLoader::getInstance()
{
	if (s_instance == nullptr)
		s_instance = new ModelGeometryLoader();
	return s_instance;
}

void ModelGeometryLoader::cleanup()
{
	if (s_instance == nullptr) {
		delete s_instance;
		s_instance = nullptr;
	}
}

ModelGeometryLoader::ModelGeometryLoader() {
}

ModelGeometryLoader::~ModelGeometryLoader()
{
	
}
