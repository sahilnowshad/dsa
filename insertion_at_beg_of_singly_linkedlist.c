void main(){
    struct node{
        int data;
        struct node*next;
    };
    struct node*head,*newnode,*temp;
    head=0;//we initilise head with 0 value 
    int choice,count=0;
    while(choice){
        newnode=(struct node*)malloc(sizeof(struct node)); // dynamically allocate memory
        printf("enter data");
        scanf("%d",&newnode->data);
        newnode->next=0;
        if(head==0){
            head=temp=newnode; /* jab pahle node hoghe too ye sab aussi ko point kray ghay
            ab ager ye pahle node nahi too ye else wala hogha implement */
        }
        else{
            temp->next=newnode;
            temp=newnode;
        }
        printf("do you want to continue (0,1)?");
        scanf("%d",&choice);

    }
    temp=head;
    // traversal of linked list
    while(temp!=0){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    // insertion of node at begning of linked list
    struct node{
     int data;
     struct node*next;

    };
    struct node*head,*newnode,*temp;
    newnode=(struct node*)malloc(size of(struct node));
    printf("enter the data you want ro enter");
    scanf("%d",&newnode->data);
    newnode->next=0;
    temp=head;
    while(temp->next!=0){
        temp=temp->next;

    }
    temp->next=newnode;
}