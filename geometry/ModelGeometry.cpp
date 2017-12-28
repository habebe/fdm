#include "ModelGeometry.hxx"
#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include <assimp/matrix4x4.h>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm> 

ModelGeometry::ModelGeometry(const aiScene* scene) {
	m_scene = scene;
}

ModelGeometry::~ModelGeometry() {
		
}

void ModelGeometry::computeBoundingBox()
{
	aiMatrix4x4 transformation;
	m_min.x = m_min.y = m_min.z = 1e10f;
	m_max.x = m_max.y = m_max.z = -1e10f;
	this->computeBoundingBox(this->m_scene->mRootNode,transformation);
	m_center.x = (m_min.x + m_max.x) / 2.0f;
	m_center.y = (m_min.y + m_max.y) / 2.0f;
	m_center.z = (m_min.z + m_max.z) / 2.0f;
}

void ModelGeometry::computeBoundingBox(const aiNode * node, aiMatrix4x4& transformation)
{
	aiMatrix4x4 previous = transformation;
	transformation *= (node->mTransformation);
	for (unsigned int n= 0; n < node->mNumMeshes; ++n) {
		const struct aiMesh* mesh = m_scene->mMeshes[node->mMeshes[n]];
		for (unsigned int t = 0; t < mesh->mNumVertices; ++t) {

			aiVector3D tmp = mesh->mVertices[t];
			tmp *= transformation;
			m_min.x = std::min(m_min.x,tmp.x);
			m_min.y = std::min(m_min.y, tmp.y);
			m_min.z = std::min(m_min.z, tmp.z);

			m_max.x = std::max(m_max.x, tmp.x);
			m_max.y = std::max(m_max.y, tmp.y);
			m_max.z = std::max(m_max.z, tmp.z);
		}
	}
	for (unsigned int n = 0; n < node->mNumChildren; ++n) {
		computeBoundingBox(node->mChildren[n],transformation);
	}
	transformation = previous;
}
