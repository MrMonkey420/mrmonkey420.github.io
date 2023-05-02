// This should be in the window/camera module
bool isBoxInView(const b2Vec2& position, const b2Vec2& dimensions) {

	// We need to scale the screen dimensions so it can work with entities position
	b2Vec2 scaledScreenDimensions = (screenWidth, screenHeight) / scale;

	// The minimum distance before a collision occurs
	const float COLLISION_DISTANCE_X = dimensions.x / 2.0f + scaledScreenDimensions.x / 2.0f;
	const float COLLISION_DISTANCE_Y = dimensions.y / 2.0f + scaledScreenDimensions.y / 2.0f;

	// Center position of the entity
	b2Vec2 centerEntityPos = position + dimensions / 2.0f;
	// Center position of the camera
	b2Vec2 centerCameraPos = CameraPosition;
	// Vector from the entity to the camera
	b2Vec2 distVec = centerEntityPos - centerCameraPos;

	// Get the depth of the collision
	float xDepth = COLLISION_DISTANCE_X - abs(distVec.x);
	float yDepth = COLLISION_DISTANCE_Y - abs(distVec.y);

	// If either the depths are > 0 then we have a collision
	if (xDepth > 0 && yDepth > 0) { return true; }

	return false;
}


// In the zone where you draw all the textures type this
for (int i = 0; i < entityArray[].size; i++) {
	if (isBoxInView(entityArray[i].GetPosition(), entityArray[i].GetDimensions()) {
		app->render->DrawTexture(entityArray[i].texture);
	}
}