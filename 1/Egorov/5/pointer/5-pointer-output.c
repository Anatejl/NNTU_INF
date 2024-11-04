#include "5-pointer-header.h"

void do_output(Company* company){

    //output the results
    printf("\nNumber of employees per department:\n");

    for (int i = 0; i < DEPT_COUNT; ++i) {
        
        printf("Department %d has %d employee(s)\n", company->known_departments[i], company->department_counts[i]);
    
    }

    int check_summ_dept = 0;

    for(int i = 0; i < DEPT_COUNT; ++i){
        check_summ_dept += company->department_counts[i];
    }

    if (check_summ_dept == HR_COUNT){
        printf("SUCCESS!");
    }
    else{
        printf("FAILURE");
    }
}