disableSerialization;
private ["_unit","_display","_pitch","_roll","_bubblePosX","_bubblePosY","_angle"];
_unit = vehicle player;
uiNamespace setVariable ["wog_pab2m_level_gui", _this select 0];
_display = _this select 0;
if ((isNull _display) || (_unit != (vehicle player))) exitWith {};

waitUntil {
	
	//пузырьковый уровень
	_pitch = asin ((AGLToASL (_unit modelToWorld (_unit selectionPosition "roll_point_1")) vectorFromTo AGLToASL (_unit modelToWorld (_unit selectionPosition "roll_point_2"))) select 2);
	_roll = asin ((AGLToASL (_unit modelToWorld (_unit selectionPosition "pitch_point_2")) vectorFromTo AGLToASL (_unit modelToWorld (_unit selectionPosition "pitch_point_1"))) select 2);
	
	_angle = _pitch atan2 _roll;
	_bubblePosX = (-1)*(cos _angle)*linearConversion [0, 0.5, abs(_roll), 0, 0.34, true];
	_bubblePosY = (sin _angle)*linearConversion [0, 0.5, abs(_pitch), 0, 0.34, true];
	
	(_display displayCtrl 77808) ctrlSetPositionX safeZoneX + safeZoneH*3/4*0.15 + safeZoneH*3/4*0.1*_bubblePosX;
	(_display displayCtrl 77808) ctrlSetPositionY safeZoneY + safeZoneH*0.75 + safeZoneH*0.1*_bubblePosY;
	(_display displayCtrl 77808) ctrlCommit 0.5;
	
	if (vehicle player == player) then
	{
		("wog_pab2m_level_gui_layer" call BIS_fnc_rscLayer) cutText ["","PLAIN"];
	};
	
	sleep 0.05;	
	isNull(uiNamespace getVariable ["wog_pab2m_level_gui", displayNull])
};
/*

//Y=safeZoneH*0.1*0.34
//X=safeZoneH*3/4*0.1*0.34