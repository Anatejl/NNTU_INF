#include "small_rejector.h"

void smallRejectorInit(SmallRejector& instance,
		const SmallRejectorParameters& params) {
	instance.params = params;
	instance.extension.n = 0;
	instance.extension.x_prev = 0; /*any*/
}

void smallRejectorDestroy(SmallRejector& /*instance*/) {
}

void smallRejectorProcess(SmallRejector& instance,
		const InputItem& input, SmallRejectorOutput& output) {
	SmallRejectorExtension extension;
	if ((instance.extension.n == 0) || input.x < instance.params.k * instance.extension.x_prev) {
		int y = input.x;
		output.resize(1);
		output[0].y = y;
	} else {
		output.clear();
	}
	extension.x_prev = input.x;
	extension.n = instance.extension.n + 1;

	instance.output = output;
	instance.extension = extension;
	return;
}

