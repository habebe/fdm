#include "ModelGeometryLoader.hxx"
#include "ModelGeometry.hxx"
#include <iostream>
#include <QCommandLineParser>

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

static void setupCommandLineParser(QCommandLineParser& parser) {
	parser.setApplicationDescription("dumps geometry content to stdout.");
	parser.addHelpOption();
	parser.addVersionOption();
	parser.addPositionalArgument("path", QCoreApplication::translate("path", "path of the file to import."));
	
	QCommandLineOption verboseOption("verbose", QCoreApplication::translate("main", "Verbose mode."));
	parser.addOption(verboseOption);
}

int main(int argc, char** argv) {
	QCoreApplication app(argc, argv);
	QCoreApplication::setApplicationName("dump");
	QCoreApplication::setApplicationVersion("1.0");
	QCommandLineParser parser;
	setupCommandLineParser(parser);
	parser.process(app);
	const QStringList path = parser.positionalArguments();
	ModelGeometryLoader* loader = ModelGeometryLoader::getInstance();
	//ModelGeometry* model = loader->load("d:\\dev\\build.test\\models\\OBJ\\box.obj");
	ModelGeometry* model = loader->load(path.at(0).toStdString().c_str());

	std::cout << "Model:" << model << "\n";
	model->computeBoundingBox();
	dump(model);
	ModelGeometryLoader::cleanup();
	return 0;
}