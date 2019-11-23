#include <gtest/gtest.h>
#include "linked_list.h"

TEST(add_to_list,normal) {
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));

    head->next=NULL; 
    head->data=str; 
    head->index=0;

    i=add_to_list(head,str1);
    EXPECT_EQ(1,i);

    i=add_to_list(head,str2);
    EXPECT_EQ(2,i);

    i=add_to_list(head,str3);
    EXPECT_EQ(3,i);

    i=add_to_list(head,str4);
    EXPECT_EQ(4,i);

    i=add_to_list(head,str5);
    EXPECT_EQ(5,i);

    i=add_to_list(head,str6);
    EXPECT_EQ(6,i);

}

TEST(add_to_list, nullList) {
    char str[15]="List Start";
    char str1[10]="zero";
    int i;

    linked_list *head= NULL;

    i = add_to_list(head,str1);
    EXPECT_EQ(-1,i);

}

TEST(add_to_list, nullString) {
    char str[15]="List Start";
    char* str1= '\0';
    int i;

    //str1[0] = NULL;
    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));
    head->next=NULL; 
    head->data=str; 
    head->index=0;

    i = add_to_list(head,str1);
    EXPECT_EQ(-1,i);

}

/***************************************************************************/


/***************************************************************************/
TEST(display_item, normal)
{
    int result;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    display_item(head->next);
    EXPECT_EQ(head->next->index,1);
    EXPECT_EQ(i,1);
    EXPECT_STREQ(head->next->data,str1);

    i=add_to_list(head,str2);
    display_item(head->next->next);
    EXPECT_EQ(head->next->next->index,2);
    EXPECT_EQ(i,2);
    EXPECT_STREQ(head->next->next->data,str2);

    i=add_to_list(head,str3);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->index,3);
    EXPECT_EQ(i,3);
    EXPECT_STREQ(head->next->next->next->data,str3);

    i=add_to_list(head,str4);
    display_item(head->next->next->next);
    EXPECT_EQ(head->next->next->next->next->index,4);
    EXPECT_EQ(i,4);
    EXPECT_STREQ(head->next->next->next->next->data,str4);

    i=add_to_list(head,str5);
    display_item(head->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->index,5);
    EXPECT_EQ(i,5);
    EXPECT_STREQ(head->next->next->next->next->next->data,str5);

    i=add_to_list(head,str6);
    display_item(head->next->next->next->next->next);
    EXPECT_EQ(head->next->next->next->next->next->next->index,6);
    EXPECT_EQ(i,6);
    EXPECT_STREQ(head->next->next->next->next->next->next->data,str6);
}

TEST(display_item, nullList) {
    char str[15]="List Start";
    int i;

    linked_list *head= NULL;

    i = display_item(head);
    EXPECT_EQ(-1,i);

}
/***************************************************************************/
TEST(display_list, nullList)
{
    int i;
    char str[15]="List Start";

    linked_list *head = NULL;  

    i = display_list(head);
    EXPECT_EQ(i, -1);
}

TEST(display_list, emptyList)
{
    int i;
    char str[15]="List Start";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i = display_list(head);
    EXPECT_EQ(i, 0);
}


TEST(display_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    i = display_list(head);
    EXPECT_EQ(i, 6);
}

///////////////////////////////////////////////////////////////
TEST(search_from_list,emptyList)
{
    linked_list* find;
    char str[15]="List Start";
    char str1[10]="zero";

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    find = search_from_list(head, str1);
    EXPECT_EQ(find, (linked_list*) NULL);
}

TEST(search_from_list, notFound)
{
    linked_list* find;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="not found";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);

    find = search_from_list(head, str4);
    EXPECT_EQ(find, (linked_list*) NULL);
}

TEST(search_from_list, normal1)
{
    linked_list* find;
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="not found";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);

    find = search_from_list(head, str3);
    EXPECT_EQ(find, head->next->next->next);
}
TEST(search_from_list, normal2)
{
    char str[15]="List Start";
    char str1[15]="second";
    char str2[15]="third";

    linked_list *find;
    struct linked_list *head;

    head = (struct linked_list*) malloc(sizeof(linked_list));
    head->data=str;
    head->index=0;


    head->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->data=str1;
    head->next->index=1;

    head->next->next->next = (struct linked_list*) malloc(sizeof(linked_list));
    head->next->next->index=2;
    head->next->next->data=str2;

    head->next->next->next->next = NULL;

    find = search_from_list(head,(char *)"third");

    EXPECT_EQ(find->index,2);
    EXPECT_STREQ(str2,find->data);
}
////////////////////////////////////////////////////////////////////

TEST(delete_from_list,normal)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *find;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    i = delete_from_list(head, 3);
    EXPECT_EQ(i, 5);
    
    find = search_from_list(head,str3);
    EXPECT_EQ(find, (linked_list*) NULL);
}

TEST(delete_from_list,deleteLastNode)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *find;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    i = delete_from_list(head, 6);
    EXPECT_EQ(i, 5);
    
    find = search_from_list(head,str6);
    EXPECT_EQ(find, (linked_list*) NULL);
}

TEST(delete_from_list,wrongIndex)
{
    char str[15]="List Start";
    char str1[10]="zero";
    char str2[10]="first";
    char str3[10]="second";
    char str4[10]="third";
    char str5[10]="fourth";
    char str6[10]="fifth";
    int i;
    linked_list *find;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i=add_to_list(head,str1);
    i=add_to_list(head,str2);
    i=add_to_list(head,str3);
    i=add_to_list(head,str4);
    i=add_to_list(head,str5);
    i=add_to_list(head,str6);


    i = delete_from_list(head, 7);
    EXPECT_EQ(i, -1);

}

TEST(delete_from_list, emptyList)
{
    linked_list* find;
    char str[15]="List Start";
    char str1[10]="zero";
    int i;

    linked_list *head = (struct linked_list*) malloc(sizeof(linked_list));  

    head->next=NULL;
    head->data=str;
    head->index=0;

    i = delete_from_list(head, 3);
    EXPECT_EQ(i, -1);
}
