#include "app.hpp"


namespace rack {


void RackScrollWidget::step() {
	Vec pos = gMousePos.minus(getAbsolutePos());
	// Scroll rack if dragging cable near the edge of the screen
	if (gRackWidget->wireContainer->activeWire) {
		float margin = 20.0;
		float speed = 15.0;
		if (pos.x <= margin)
			offset.x -= speed;
		if (pos.x >= box.size.x - margin)
			offset.x += speed;
		if (pos.y <= margin)
			offset.y -= speed;
		if (pos.y >= box.size.y - margin)
			offset.y += speed;
	}
	ScrollWidget::step();
}


} // namespace rack
