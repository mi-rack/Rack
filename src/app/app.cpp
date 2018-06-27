#include "app.hpp"


namespace mirack {

std::string gApplicationName = "miRack";
std::string gApplicationVersion = TOSTRING(VERSION);
std::string gApiHost = "http://localhost:8081";

RackWidget *gRackWidget = NULL;
Toolbar *gToolbar = NULL;
RackScene *gRackScene = NULL;


void appInit() {
	gRackScene = new RackScene();
	gScene = gRackScene;
}

void appDestroy() {
	delete gRackScene;
}


json_t *colorToJson(NVGcolor color) {
	json_t *colorJ = json_object();
	json_object_set_new(colorJ, "r", json_real(color.r));
	json_object_set_new(colorJ, "g", json_real(color.g));
	json_object_set_new(colorJ, "b", json_real(color.b));
	json_object_set_new(colorJ, "a", json_real(color.a));
	return colorJ;
}

NVGcolor jsonToColor(json_t *colorJ) {
	NVGcolor color;
	color.r = json_number_value(json_object_get(colorJ, "r"));
	color.g = json_number_value(json_object_get(colorJ, "g"));
	color.b = json_number_value(json_object_get(colorJ, "b"));
	color.a = json_number_value(json_object_get(colorJ, "a"));
	return color;
}


} // namespace mirack
