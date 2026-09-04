#include <stdio.h>
struct Student{
    char name[32];
    int student_id;
    float score;
};
int main(){
    struct Student st={"hyh",1001,88.5f};
    printf("%s,%d,%.1f\n",st.name,st.student_id,st.score);
    st.score=95.0f;
    printf("%s,%d,%.1f\n", st.name, st.student_id, st.score);
    return 0;
}