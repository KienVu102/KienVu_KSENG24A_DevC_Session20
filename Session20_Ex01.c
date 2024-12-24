#include <stdio.h>
#include <string.h>

struct Book{
	char name[100];
	char author[100];
	int id;
	float price;
};

int main(){
	struct Book books [100];
	int choice, n, b, check = 0;
	do{
		printf("\nMENU\n");
		printf("1. Nhap so luong va thong tin sach\n");
		printf("2. Hien thi thong tin sach\n");
		printf("3. Them sach vao vi tri\n");
		printf("4. Xoa sach theo ma sach\n");
		printf("5. Cap nhat thong tin theo ma sach\n");
		printf("6. Sap xep sach theo gia\n");
		printf("7. Tim kiem theo ten sach\n");
		printf("8. Thoat\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				askInfo(books,&n);
				check=-1;
				break;
			
			case 2:
				if(check){
					printInfo(books,n);
				}
				break;
			
			case 3:
				if(check){
					addBook(books,&n);
				}
				break;
			
			case 4:
				if(check){
					deleteBook(books,&n);
				}
				break;
				
			case 5:
				break;
			
			case 6:
				break;
				
			case 7:
				break;
			
			case 8:
				printf("\nThoat chuong trinh\n");
				break;
				
			default:
				printf("Lua chon khong hop le. Vui long thu lai!\n");
			
		}
	}while(choice != 8);

	return 0;
}

void askInfo(struct Book books[],int *n){
	printf("Nhap so luong sach: ");
	scanf("%d",n);
	fflush(stdin);
	int i=0;
	while(i<*n){
		printf("\n=================\n");
		printf("Nhap ma sach: ");
		scanf("%d",&(books[i].id));
		fflush(stdin);
		printf("Nhap ten sach: ");
		fgets(books[i].name,sizeof books[i].name,stdin);
		books[i].name[strcspn(books[i].name,"\n")]='\0';
		printf("Nhap tac gia: ");
		fgets(books[i].author,sizeof books[i].author,stdin);
		books[i].author[strcspn(books[i].author,"\n")]='\0';
		printf("Nhap gia sach: ");
		scanf("%f",&(books[i].price));
		fflush(stdin);
		i++;
	}
}

void printInfo(struct Book books[],int n){
	int i=0;
	while(i<n){
		printf("\n================");
		printf("\nMa sach: %d\n",books[i].id);
		printf("Ten sach: %s\n",books[i].name);
		printf("Tac gia: %s\n",books[i].author);
		printf("Gia sach: %.2f\n",books[i].price);
		i++;
	}
}

void addBook(struct Book books[],int *n){
	int index;
	printf("Nhap vi tri ban muon chen sach(1->%d): ",*n);
	scanf("%d",&index);
	if(index>0&&index<=*n){
		index--;
		int i=0;
		while(*n-i>index){
			books[*n-i]=books[*n-i-1];
			i++;
		}
		printf("Nhap ma sach: ");
		scanf("%d",&(books[index].id));
		fflush(stdin);
		printf("Nhap ten sach: ");
		fgets(books[index].name,sizeof books[index].name,stdin);
		books[index].name[strcspn(books[index].name,"\n")]='\0';
		printf("Nhap tac gia: ");
		fgets(books[index].author,sizeof books[index].author,stdin);
		books[index].author[strcspn(books[index].author,"\n")]='\0';
		printf("Nhap gia sach: ");
		scanf("%f",&(books[index].price));
		fflush(stdin);
		(*n)++;
	}
}

void deleteBook(struct Book books[],int *n){
	int index,i=0,j;
	printf("vui long nhap ma muon xoa: ");
	scanf("%d",&index);
	while(i<*n){
		if(index==books[i].id){
			j=i;
			while(j<*n-1){
				books[j]=books[j+1];
				j++;
			}
			(*n)--;
		}
		i++;
	}
}
