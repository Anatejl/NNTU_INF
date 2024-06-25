#ifndef APPLICATION_H
#define APPLICATION_H

struct Application {
    int tLi;
    int tLv;
    int tRi;
    int tRv;
    int fLi;
    int fRi;
    int tCS;
    int fCS;
    bool isFirst;
    int n;
    int D;
    int xn;

    Application(): tLi(0), tLv(0), tRi(0), tRv(0), fLi(0), fRi(0),
    tCS(1), fCS(1), isFirst(true), n(0), D(0), xn(0) {}
};

bool app_get_D(Application &app);
bool app_get_element(Application &app);
bool app_output_match(Application &app);
bool app_process(Application &app);
int app_run(Application &app);

#endif // APPLICATION_H