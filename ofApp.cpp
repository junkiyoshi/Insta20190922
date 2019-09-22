#include "ofApp.h"	

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	auto len = 300;

	this->cam.begin();

	for (auto z = len * -0.5; z <= len * 0.5; z += 10) {

		vector<glm::vec3> vertices;
		for (auto param = len * -0.5; param <= len * 0.5; param++) {

			auto height = ofMap(ofNoise(param * 0.005, ofGetFrameNum() * 0.005 + z * 0.005), 0, 1, len * -0.3, len * 0.3);
			vertices.push_back(glm::vec3(param, height, z));
		}
		vertices.push_back(glm::vec3(len * 0.5, len * -0.5, z));
		vertices.push_back(glm::vec3(len * -0.5, len * -0.5, z));

		ofFill();
		ofSetColor(239);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);

		ofNoFill();
		ofSetColor(39);
		ofBeginShape();
		ofVertices(vertices);
		ofEndShape(true);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}