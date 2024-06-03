#include "small_rejector.h"

#include <iostream>

int main() {
	SmallRejectorParameters params;
	params.k = 1;
	SmallRejector operation;
	smallRejectorInit(operation, params);

	while (true) {
		InputItem input;
		std::cin >> input.x;
        //std::cout << input.x << std::endl;
		if (std::cin.eof())
			break;

		SmallRejectorOutput output;
		smallRejectorProcess(operation, input, output);

		for ( auto& item : output )
			std::cout << item.y << std::endl;
	}
	smallRejectorDestroy(operation);
	return 0;
}

#include "compressor.h"

void CompressorInit(Compressor& instance, const CompressorGroup& group){
    instance.del=group;//группа сжатия
    instance.extension.buffer.clear();//очистка буфера
    instance.extension.counter = 0;//счётчик на нуле
}

void CompressorProcess(Compressor& instance, const InputItem& input, CompressorOutput& output){

    instance.extension.buffer.push_back(input.x);//Добавление нового элемента в буфер
    if(instance.extension.buffer.size()==instance.del.b.size()){
        for (int i = 0; i < instance.del.b.size(); ++i){//проверка равности буфера и группы сжатия
            if (instance.extension.buffer[i]!=instance.del.b[i]){
                break;
            }
            instance.extension.counter++;
        }
        if (instance.extension.counter == instance.del.b.size()){//если счётчик равен длине группы сжатия (то есть буфер равен группе)
            instance.extension.buffer.clear();//очистка буфера и обнуление счетчика
            instance.extension.counter = 0;
        }
        else {//если не равен, то первый элемент буфера проходит на выход и сразу удаляется из буфера
            output.resize(1);
            output[0].y=instance.extension.buffer[0];
            instance.extension.buffer.erase(instance.extension.buffer.begin());
        }
    }



    return;
}