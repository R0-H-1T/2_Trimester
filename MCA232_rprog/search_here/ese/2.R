elements <- c(
    85,
    90,
    78,
    92,
    88,
    76,
    95,
    89,
    82,
    70,
    93,
    87
)

student_scores <- matrix(elements, nrow=4, ncol=3)
student_scores

rownames(student_scores) <- c("S1", "S2", "S3", "S4")
colnames(student_scores) <- c("Math", "English", "Science")

mean(student_scores[,1])
mean(student_scores[,2])
mean(student_scores[,3])

which.max(student_scores[,3])

which(student_scores[]<80)
which(student_scores[2,]<80)
which(student_scores[3,]<80)
