#include <stdio.h>
#include <ctype.h>

#define MAX 1000

int prec(char c){
    if(c=='+' || c=='-') return 1;
    if(c=='*' || c=='/') return 2;
    return 0;
}

void toPostfix(const char *in, char *out){
    char st[MAX];
    int top = -1, j = 0;

    for(int i = 0; in[i]; ){
        if(isspace((unsigned char)in[i])) { i++; continue; }

        if(isdigit((unsigned char)in[i])){                 // number
            while(isdigit((unsigned char)in[i])) out[j++] = in[i++];
            out[j++] = ' ';
            continue;
        }

        char c = in[i++];

        if(c == '('){
            st[++top] = c;
        } else if(c == ')'){
            while(top >= 0 && st[top] != '('){
                out[j++] = st[top--];
                out[j++] = ' ';
            }
            if(top >= 0) top--; // pop '('
        } else { // operator
            while(top >= 0 && st[top] != '(' && prec(st[top]) >= prec(c)){
                out[j++] = st[top--];
                out[j++] = ' ';
            }
            st[++top] = c;
        }
    }

    while(top >= 0){
        if(st[top] != '('){
            out[j++] = st[top];
            out[j++] = ' ';
        }
        top--;
    }
    out[j] = '\0';
}

int evalPostfix(const char *p){
    int st[MAX], top = -1;

    for(int i = 0; p[i]; ){
        if(isspace((unsigned char)p[i])) { i++; continue; }

        if(isdigit((unsigned char)p[i])){                  // number
            int v = 0;
            while(isdigit((unsigned char)p[i])) v = v * 10 + (p[i++] - '0');
            st[++top] = v;
            continue;
        }

        char op = p[i++];
        int b = st[top--], a = st[top--];

        if(op == '+') st[++top] = a + b;
        else if(op == '-') st[++top] = a - b;
        else if(op == '*') st[++top] = a * b;
        else if(op == '/') st[++top] = a / b;
    }

    return st[top];
}

int main(){
    char in[MAX], post[MAX];

    printf("Enter infix: ");
    if(!fgets(in, sizeof(in), stdin)) return 0;

    toPostfix(in, post);
    printf("Postfix: %s\n", post);
    printf("Result: %d\n", evalPostfix(post));

    return 0;
}
