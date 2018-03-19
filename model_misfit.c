#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void L2norm(float *a,float *b,int npt,float *sum);
void normalize(float *a,int n);

void main()
{
	int inum,num,i;

	int npt;

	char dirc[100],*path;

	float *vp0,*vs0,*vp1,*vs1;

	float mis_vp[50],mis_vs[50];

	float tmp;

	FILE *fp;

	npt=67500;

	vp0=(float*)calloc(npt,sizeof(float));
	vs0=(float*)calloc(npt,sizeof(float));
	vp1=(float*)calloc(npt,sizeof(float));
	vs1=(float*)calloc(npt,sizeof(float));

	fp=fopen("/home/liuq0a/tests/marmousi_onshore/model_true/proc000000_vp.bin","rb");
	fread(vp0,sizeof(float),npt,fp);
	fclose(fp);

	fp=fopen("/home/liuq0a/tests/marmousi_onshore/model_true/proc000000_vs.bin","rb");
	fread(vs0,sizeof(float),npt,fp);
	fclose(fp);

	num=50;

	printf("%08d\n",num);

	sprintf(dirc,"%08d\n",num);

	printf("%s\n",dirc);

	path=".";

	printf("%s\n",path);

	for(i=1;i<=50;i++){

		sprintf(dirc,"%s/output/model_%04d/proc000000_vp.bin",path,i);
		
		printf("%s\n",dirc);

		fp=fopen(dirc,"rb");
		fread(vp1,sizeof(float),npt,fp);
		fclose(fp);

		L2norm(vp0,vp1,npt,&mis_vp[i-1]);
	
		sprintf(dirc,"%s/output/model_%04d/proc000000_vs.bin",path,i);
		fp=fopen(dirc,"rb");
		fread(vs1,sizeof(float),npt,fp);
		fclose(fp);

		L2norm(vs0,vs1,npt,&mis_vs[i-1]);

	}

	normalize(mis_vp,50);
	normalize(mis_vs,50);

	fp=fopen("mis_vp.bin","wb");
	fwrite(mis_vp,sizeof(float),50,fp);
	fclose(fp);

	fp=fopen("mis_vs.bin","wb");
	fwrite(mis_vs,sizeof(float),50,fp);
	fclose(fp);

}

void L2norm(float *a,float *b,int n,float *sum){

	int i;
	
	float tmp=0;	

	for(i=0;i<n;i++){
		tmp+=(a[i]-b[i])*(a[i]-b[i]);		
	}
	
	*sum=pow(sqrt(tmp),1);
}

void normalize(float *a,int n){

	int i;

	float tmp;
	
	tmp=a[0];

	for(i=0;i<n;i++){
		a[i]/=tmp;
	}
}
