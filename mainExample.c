#include <stdio.h>

// פונקציה להזזת איברים שמאלה (אסור לשנות)
void f(int *a, int j) {
    for (int i = 0; i < j; ++i) {
        *(a + i) = a[i + 1];
    }
}

// פונקציה למציאת k הערכים הגדולים ביותר
void maxK(int *arr, int n, int *max, int k) {
    int temp[n]; // יצירת עותק בגודל מדויק של arr

    // העתקת הערכים מ-`arr` ל-`temp`
    for (int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }

    int size = n; // גודל נוכחי של temp

    // חיפוש k הערכים הגדולים ביותר
    for (int i = 0; i < k; i++) {
        int maxIdx = 0;

        // חיפוש הערך הגדול ביותר
        for (int j = 1; j < size; j++) {
            if (temp[j] > temp[maxIdx]) {
                maxIdx = j;
            }
        }

        // שמירת הערך הגדול ביותר במערך `max`
        max[i] = temp[maxIdx];

        // שימוש בפונקציה `f()` להסרת הערך הגדול ביותר מ-`temp`
        f(temp + maxIdx, size - maxIdx - 1);
        size--; // הפחתת גודל `temp` לאחר הסרת איבר
    }
}

// פונקציה ראשית (main) לבדיקה
int main() {
iteration 1                        55    42  4   4
    int a[] = {2, 15, 3, 142, 5, 1, 1024, 55, 42, 4}; // מערך מקור
    // size -- removing 4 from the end of the array.
    // so after first iteration array looks like that
    //         {2, 15, 3, 142, 5, 1, 55, 42, 4, 4};

// iteration 2 the biggest number is 142, his index is 3
//             5   1  55  42  4  4  4
// {2, 15, 3, 142, 5, 1, 55, 42, 4, 4};
// so we get 
// {2, 15, 3, 5, 1, 55, 42, 4, 4, 4};
    int m[4]; // מערך לתוצאה

    maxK(a, 10, m, 4); // קריאה לפונקציה

    // הדפסת התוצאה
    printf("הערכים הגדולים ביותר הם: ");
    for (int i = 0; i < 4; i++)
        printf("%d ", m[i]);

    printf("\n");


        // הדפסת התוצאה
        printf("test test ");
        for (int i = 0; i < 10; i++)
            printf("%d ", a[i]);
    
    return 0;
}
