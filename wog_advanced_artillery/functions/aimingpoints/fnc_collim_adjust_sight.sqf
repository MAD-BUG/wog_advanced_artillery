/*
 * Author: p1nga
 *
 * Toggle Aim Down Collimator Iron Sights.
 *
 * Argument:
 * 0: Any object <OBJECT>
 *
 * Return Value:
 * None
 *
 * Public: Yes
 */
//#include "script_component.hpp"
params ["_collimator"];
private ["_pos","_camera","_align_H", "_align_V"];

//diag_log _collimator;
acex_aligningCollimator = _collimator;
_pos = acex_aligningCollimator modelToWorld (acex_aligningCollimator selectionPosition "eye");
_camera = "camera" camCreate _pos;
_camera cameraEffect ["internal", "back"];
_camera camSetTarget (acex_aligningCollimator modelToWorld (acex_aligningCollimator selectionPosition "look"));
/*opticsZoomMin = 0.25;
opticsZoomMax = 1.25;
opticsZoomInit = 0.75;*/
_camera camSetFovRange [0.25, 1.25];
_camera camSetFov 0.3;
_camera camCommit 0.1;

showCinemaBorder false;
acex_aimingpoints_collimatorAlignHorz = acex_aligningCollimator animationPhase "collimator_rotation";
acex_aimingpoints_collimatorAlignVert = acex_aligningCollimator animationPhase "collimator_elevation";
///////////////////////////////////////////////////////////////////
[] call wog_fnc_collim_addKeys;
_func = {
	_camera = (_this select 0) select 0;
	if(acex_aimingpoints_aligning) then {
		toFixed 6;
		_pos = acex_aligningCollimator modelToWorld (acex_aligningCollimator selectionPosition "eye");
		_camera camSetPos _pos;
		_camera camSetTarget (acex_aligningCollimator modelToWorld (acex_aligningCollimator selectionPosition "look"));
		//camUseNVG ace_sys_nvg_on;
		_camera camSetFov 0.3;
		_camera camCommit 0.1;
	} else {
		_camera cameraEffect ["terminate", "back"];
		//cutrsc ["default", "PLAIN DOWN"];
		camDestroy _camera;
		[] call wog_fnc_collim_removeKeys;
		[(_this select 1)] call CBA_fnc_removePerFrameHandler;
	};
};
acex_aimingpoints_aligning = true;
[_func, 0.05, [_camera]] call CBA_fnc_addPerFrameHandler;