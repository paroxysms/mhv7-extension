use crate::extensionv7::*;

mod extensionv7;

#[no_mangle]
extern "stdcall" fn button_callback(obj: *mut MegaHackExt_Button) {

}

#[no_mangle]
extern "stdcall" fn color_callback(obj: &mut MegaHackExt_ColourPicker, col: MegaHackExt_Colour) {

}

#[no_mangle]
extern "stdcall" fn on_startup() {

}