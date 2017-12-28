#include "ModelGeometryLoader.hxx"
#include "ModelGeometry.hxx"
#include <iostream>

void dump(const aiVector3D& v) {
	std::cout << v.x << "," << v.y << "," << v.z << std::endl;
}

void dump(ModelGeometry* model) {
	std::cout << "center:";
	dump(model->center());
	std::cout << "min   :";
	dump(model->min());
	std::cout << "max   :";
	dump(model->max());
}


int main(int argc,const char** argv) {
	//std::cout << "ARGV:" << argv[1] << "\n";
	ModelGeometryLoader* loader = ModelGeometryLoader::getInstance();
	ModelGeometry* model = loader->load("d:\\dev\\build.test\\models\\OBJ\\box.obj");
	std::cout << "Model:" << model << "\n";
	model->computeBoundingBox();
	dump(model);
	ModelGeometryLoader::cleanup();
	return 0;
}