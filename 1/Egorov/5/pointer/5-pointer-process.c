#include "5-pointer-header.h"

void do_process(Company* company){

    //count employees per department
    for (int i = 0; i < HR_COUNT; ++i) {

        for (int j = 0; j < DEPT_COUNT; ++j) {
            
            if (company->personnel[i].department == company->known_departments[j]) {
                
                company->department_counts[j]++;
                break;
            
            }
        }
    }
} 