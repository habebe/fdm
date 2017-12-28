#pragma once
#include <assimp/Importer.hpp>   
class ModelGeometry;
struct aiLogStream;
class ModelGeometryLoader {
public:
	ModelGeometry* load(const char* path);
	static ModelGeometryLoader* getInstance();
	static void cleanup();

private:
	ModelGeometryLoader();
	~ModelGeometryLoader();
private:
	static ModelGeometryLoader * s_instance;
	Assimp::Importer m_importer;
};