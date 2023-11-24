#include <stdio.h>


typedef  unsigned char u8;
typedef unsigned int u32;


int binay_Search(u32 arr[],int size,u32 target);


typedef struct
{
    unsigned char colors[3];
    u8 intensity;

} CanData_t;

CanData_t CanDataArr[78];


const u32 u32customerColor[]={
{(u32)84255	},
{(u32)95255	},
{(u32)106255	},
{(u32)127255	},
{(u32)138255	},
{(u32)161255	},
{(u32)173255	},
{(u32)186255	},
{(u32)200255	},
{(u32)201110	},
{(u32)201110	},
{(u32)234255	},
{(u32)254255	},
{(u32)255021	},
{(u32)255102	},
{(u32)255136	},
{(u32)255164	},
{(u32)255188	},
{(u32)255212	},
{(u32)255234	},
{(u32)2146255	},
{(u32)18092255	},
{(u32)18092255	},
{(u32)24255046	},
{(u32)34131232	},
{(u32)54138233	},
{(u32)65082255	},
{(u32)69255044	},
{(u32)90081255	},
{(u32)110080255	},
{(u32)113255043	},
{(u32)114195255	},
{(u32)127078255	},
{(u32)139123255	},
{(u32)142077255	},
{(u32)142255042	},
{(u32)157076255	},
{(u32)165255042	},
{(u32)170074255	},
{(u32)185255041	},
{(u32)197070255	},
{(u32)203255040	},
{(u32)209068255	},
{(u32)219255039	},
{(u32)234103058	},
{(u32)235168086	},
{(u32)235255038	},
{(u32)237062255	},
{(u32)238242032	},
{(u32)250213185	},
{(u32)251255037	},
{(u32)255000049	},
{(u32)255000077	},
{(u32)255000099	},
{(u32)255000119	},
{(u32)255000138	},
{(u32)255000156	},
{(u32)255000176	},
{(u32)255006000	},
{(u32)255011196	},
{(u32)255028000	},
{(u32)255035219	},
{(u32)255051244	},
{(u32)255062000	},
{(u32)255085000	},
{(u32)255105000	},
{(u32)255125000	},
{(u32)255139071	},
{(u32)255155005	},
{(u32)255168010	},
{(u32)255180015	},
{(u32)255192019	},
{(u32)255205023	},
{(u32)255218027	},
{(u32)255221000	},
{(u32)255231030	},
{(u32)255244034	},
{(u32)255255255	},


};

const u8 u8OutColor[][4] =
        {
                {(u8)9	,(u8)89	,(u8)255	,(u8)66	},
                {(u8)10	,(u8)108	,(u8)255	,(u8)66	},
                {(u8)12	,(u8)128	,(u8)255	,(u8)66	},
                {(u8)14	,(u8)177	,(u8)254	,(u8)66	},
                {(u8)15	,(u8)207	,(u8)255	,(u8)66	},
                {(u8)17	,(u8)255	,(u8)234	,(u8)66	},
                {(u8)16	,(u8)255	,(u8)202	,(u8)66	},
                {(u8)16	,(u8)255	,(u8)174	,(u8)66	},
                {(u8)15	,(u8)254	,(u8)149	,(u8)66	},
                {(u8)57	,(u8)255	,(u8)26	,(u8)66	},
                {(u8)50	,(u8)255	,(u8)17	,(u8)66	},
                {(u8)14	,(u8)255	,(u8)109	,(u8)66	},
                {(u8)14	,(u8)254	,(u8)91	,(u8)66	},
                {(u8)53	,(u8)255	,(u8)8	,(u8)66	},
                {(u8)12	,(u8)255	,(u8)16	,(u8)66	},
                {(u8)13	,(u8)255	,(u8)26	,(u8)66	},
                {(u8)13	,(u8)255	,(u8)37	,(u8)66	},
                {(u8)13	,(u8)255	,(u8)49	,(u8)66	},
                {(u8)13	,(u8)253	,(u8)61	,(u8)66	},
                {(u8)14	,(u8)255	,(u8)76	,(u8)66	},
                {(u8)15	,(u8)239	,(u8)255	,(u8)66	},
                {(u8)27	,(u8)90	,(u8)255	,(u8)66	},
                {(u8)60	,(u8)238	,(u8)255	,(u8)66	},
                {(u8)67	,(u8)255	,(u8)8	,(u8)66	},
                {(u8)68	,(u8)255	,(u8)154	,(u8)66	},
                {(u8)38	,(u8)255	,(u8)152	,(u8)66	},
                {(u8)46	,(u8)89	,(u8)255	,(u8)66	},
                {(u8)80	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)65	,(u8)90	,(u8)255	,(u8)66	},
                {(u8)86	,(u8)90	,(u8)255	,(u8)66	},
                {(u8)94	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)77	,(u8)255	,(u8)108	,(u8)66	},
                {(u8)108	,(u8)90	,(u8)255	,(u8)66	},
                {(u8)199	,(u8)249	,(u8)161	,(u8)66	},
                {(u8)131	,(u8)91	,(u8)254	,(u8)66	},
                {(u8)108	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)156	,(u8)92	,(u8)255	,(u8)66	},
                {(u8)122	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)183	,(u8)92	,(u8)255	,(u8)66	},
                {(u8)136	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)232	,(u8)89	,(u8)244	,(u8)66	},
                {(u8)150	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)246	,(u8)84	,(u8)228	,(u8)66	},
                {(u8)164	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)255	,(u8)65	,(u8)28	,(u8)66	},
                {(u8)255	,(u8)221	,(u8)57	,(u8)66	},
                {(u8)179	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)251	,(u8)67	,(u8)179	,(u8)66	},
                {(u8)218	,(u8)255	,(u8)10	,(u8)66	},
                {(u8)255	,(u8)247	,(u8)37	,(u8)66	},
                {(u8)195	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)235	,(u8)7	,(u8)6	,(u8)33	},
                {(u8)255	,(u8)10	,(u8)14	,(u8)33	},
                {(u8)255	,(u8)13	,(u8)22	,(u8)33	},
                {(u8)255	,(u8)16	,(u8)32	,(u8)33	},
                {(u8)255	,(u8)20	,(u8)43	,(u8)33	},
                {(u8)255	,(u8)25	,(u8)56	,(u8)33	},
                {(u8)255	,(u8)30	,(u8)71	,(u8)33	},
                {(u8)253	,(u8)18	,(u8)0	,(u8)33	},
                {(u8)255	,(u8)36	,(u8)90	,(u8)33	},
                {(u8)253	,(u8)31	,(u8)1	,(u8)33	},
                {(u8)254	,(u8)44	,(u8)113	,(u8)33	},
                {(u8)253	,(u8)54	,(u8)142	,(u8)66	},
                {(u8)255	,(u8)48	,(u8)1	,(u8)33	},
                {(u8)254	,(u8)65	,(u8)2	,(u8)33	},
                {(u8)253	,(u8)86	,(u8)2	,(u8)33	},
                {(u8)254	,(u8)111	,(u8)3	,(u8)33	},
                {(u8)255	,(u8)177	,(u8)3	,(u8)66	},
                {(u8)255	,(u8)154	,(u8)4	,(u8)66	},
                {(u8)255	,(u8)174	,(u8)5	,(u8)66	},
                {(u8)254	,(u8)194	,(u8)5	,(u8)66	},
                {(u8)255	,(u8)215	,(u8)6	,(u8)66	},
                {(u8)255	,(u8)237	,(u8)6	,(u8)66	},
                {(u8)251	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)255	,(u8)228	,(u8)12	,(u8)66	},
                {(u8)231	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)212	,(u8)255	,(u8)7	,(u8)66	},
                {(u8)196	,(u8)255	,(u8)85	,(u8)100	},

        };

void getCanData(int LedIndex,CanData_t*pCanData)
{
/*
  //  you can insert the data you want here if you want to test
    pCanData->colors[0]=18;
    pCanData->colors[1]=92;
    pCanData->colors[2]=25;
    */



    u32 target=(pCanData->colors[0]*(u32)1000000)+(pCanData->colors[1]*(u32)1000)+(pCanData->colors[2]);


   int index=binay_Search(u32customerColor,78,target);
    /*you can print the index of the corresponding output here ,-1 mean not found
    printf("\n==========%d\n",index);
    */

    if(index==-1)      // -1 means numbers are not in the table
    {
        CanDataArr[LedIndex].colors[0]=pCanData->colors[0];
        CanDataArr[LedIndex].colors[1]=pCanData->colors[1];
        CanDataArr[LedIndex].colors[2]=pCanData->colors[2];
        CanDataArr[LedIndex].intensity=pCanData->intensity;
    }
    else{           //numbers are in the table
        CanDataArr[LedIndex].colors[0]=u8OutColor[index][0];
        CanDataArr[LedIndex].colors[1]=u8OutColor[index][1];
        CanDataArr[LedIndex].colors[2]=u8OutColor[index][2];
        CanDataArr[LedIndex].intensity=u8OutColor[index][3];
    }


}


void SetPWM(int LedIndex,unsigned char red,unsigned char green,unsigned char blue)
{
    printf("for led :%3d red= %d green=%d  blue=%d\n",LedIndex,red,green,blue);
}



int main()
{

    int i;

    while(1)
    {
        for(i=0; i<78; i++)
        {
            getCanData(i,&CanDataArr[i]) ;
            SetPWM(i,CanDataArr[i].colors[0],CanDataArr[i].colors[1],CanDataArr[i].colors[2]);
        }

    }

    return 0;
}



int binay_Search(u32 arr[],int size,u32 target){

    //implement binary search

    int first=0,last=size-1;

    int mid=(first+last)/2;

    while(first<=last){
        mid=(first+last)/2;

        if(target==arr[mid]){
            return mid;
        }

        else if(target<arr[mid]){
            last=mid-1;
        }
        
        else if(target>arr[mid]){
            first=mid+1;
        }


    }

    return -1;


}




