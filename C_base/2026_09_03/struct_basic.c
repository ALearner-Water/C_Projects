#include <stdio.h>
struct Student{
    char name[32];
    int student_id;
    float score;
};
int main(void){
    struct Student st={"hyh",1001,88.5f};
    printf("%s,%d,%.1f\n",st.name,st.student_id,st.score);
    st.score=95.0f;
    printf("%s,%d,%.1f\n", st.name, st.student_id, st.score);
    struct Student *struent_ptr=&st;
    struent_ptr->score=90.f;
    printf("%.1f",st.score);
    return 0;
}