#pragma once

#include <assimp/vector3.h>
#include <assimp/scene.h>
class ModelGeometry {
public:
	ModelGeometry(const aiScene* scene);
	~ModelGeometry();
	void computeBoundingBox();
	void computeBoundingBox(
		const aiNode * node,aiMatrix4x4& identity);

	const aiVector3D& min() const { return m_min; }
	const aiVector3D& max() const { return m_max; }
	const aiVector3D& center() const { return m_center; }

private:
	aiVector3D m_min;
	aiVector3D m_max;
	aiVector3D m_center;
	const aiScene* m_scene;
};