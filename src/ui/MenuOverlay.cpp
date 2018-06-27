#include "ui.hpp"
#include "window.hpp"


namespace mirack {


void MenuOverlay::onResize() {
	// Fit all children in the box
	for (Widget *child : children) {
		child->box = child->box.nudge(box.zeroPos());
	}

	Widget::onResize();
}

void MenuOverlay::onMouseDown(EventMouseDown &e) {
	Widget::onMouseDown(e);
	if (!e.consumed) {
		// deletes `this`
		gScene->setOverlay(NULL);
		e.consumed = true;
	}
}

void MenuOverlay::onHoverKey(EventHoverKey &e) {
	switch (e.key) {
		case GLFW_KEY_ESCAPE: {
			gScene->setOverlay(NULL);
			e.consumed = true;
			return;
		} break;
	}

	if (!e.consumed) {
		// Recurse children but consume the event
		Widget::onHoverKey(e);
		e.consumed = true;
	}
}


} // namespace mirack
