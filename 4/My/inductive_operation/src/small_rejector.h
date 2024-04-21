//small_rejector.h
#pragma once

#include "input_item.h"
#include "output_item.h"

#include <vector>

using SmallRejectorOutput = std::vector<OutputItem>;

struct SmallRejectorParameters {
	int k;
};

struct SmallRejectorExtension {
	int x_prev;
	int n;
};

struct SmallRejector {
	SmallRejectorOutput output;
	SmallRejectorParameters params;
	SmallRejectorExtension extension;
};

void smallRejectorInit(SmallRejector& instance, const SmallRejectorParameters& params);
void smallRejectorDestroy(SmallRejector& instance);
void smallRejectorProcess(SmallRejector& instance, const InputItem& input, SmallRejectorOutput& output);

