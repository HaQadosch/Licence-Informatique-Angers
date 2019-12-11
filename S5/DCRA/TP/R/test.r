cat("table des puissances inférieures ou égales à 1 million")
mat=matrix(,nrow=10,ncol=10)
for(i in 1:10){
	for(j in 1:10){
		mat[i][j]=i^j
	}
}
warnings()
mat
