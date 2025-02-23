#include <stdio.h>
#include <stdlib.h>

// פונקציה להזזת איברים שמאלה
void f(int *a, int j) {
    for (int i = 0; i < j; ++i) {
        *(a + i) = a[i + 1];
    }
}

// פונקציה למציאת k הערכים הגדולים ביותר
void maxK(int *arr, int n, int *max, int k) {
    // יצירת עותק של arr כדי לשמור על הסדר המקורי
    int *temp = (int *)malloc(n * sizeof(int));
    if (!temp) {
        printf("Error: Memory allocation failed\n");
        return;
    }

    // העתקת הערכים ל-temp
    for (int i = 0; i < n; i++)
        temp[i] = arr[i];

    int size = n; // גודל המערך שאנו עובדים עליו

    for (int i = 0; i < k; i++) {
        int maxIdx = 0;

        // חיפוש המספר הגדול ביותר
        for (int j = 1; j < size; j++) {
            if (temp[j] > temp[maxIdx]) {
                maxIdx = j;
            }
        }

        // שמירת המספר הגדול במערך max
        max[i] = temp[maxIdx];

        // שימוש בפונקציה f כדי להסיר את הערך שנבחר
        f(temp + maxIdx, size - maxIdx - 1);
        size--; // הקטנת גודל המערך לאחר מחיקת איבר
    }

    free(temp); // שחרור זיכרון מוקצה
}

// פונקציית main לבדיקה
int main() {
    int a[] = {2, 15, 3, 142, 5, 1, 1024, 55, 42, 4};
    int m[4]; // מערך לתוצאה

    maxK(a, 10, m, 4);

    // הדפסת התוצאה
    printf("הערכים הגדולים ביותר הם: ");
    for (int i = 0; i < 4; i++)
        printf("%d ", m[i]);
    
    printf("\n");


    
    // test
    printf("test test \n\n");
    for (int i = 0; i < 10; i++)
    printf("%d ", a[i]);    
    
    return 0;
}



