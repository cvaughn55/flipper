#include <stdio.h>
#define __private_include__
#include <flipper.h>
#include <platform/posix.h>
#include <platform/fvm.h>

int main(int argc, char *argv[]) {

	//flipper_attach_endpoint("fvm", &lf_fvm_ep);
	flipper_attach();

	/* Create an empty message runtime module instance. */
	struct _fmr_module _lf_led_module;
	_lf_led_module.device = flipper.device;

	struct _fmr_module _lf_button_module;
	_lf_button_module.device = flipper.device;

	/* Bind the empty instance to the default 'led' module which comes pre-loaded on all devices. */
	int _e = fmr_bind(&_lf_led_module, "_lf_led");
	if (_e < lf_success) {
		error_raise(E_MODULE, "Failed to bind to LED module.");
	}
	_lf_led_module.identifier = 1;

	_e = fmr_bind(&_lf_button_module, "_lf_button");
	if (_e < lf_success) {
		error_raise(E_MODULE, "Failed to bind to button module.");
	}
	_lf_button_module.identifier = 0;

	/* Perform the function invocation. */
	uint32_t result = lf_invoke(&_lf_button_module, _button_read, fmr_build(0));
	printf("The value was 0x%08x.\n", result);

    return 0;
}
