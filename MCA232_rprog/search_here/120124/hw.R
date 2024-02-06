library(ggplot2)

# 1
# create the dataset

dataset <- data.frame(
    time = c(5,7,12,16,20),
    mass = c(40,120,180,210,240)
)

# 1.1
# get some summary about the dataset
summary(dataset)

# 2
# compute the correlation coefficient
cor_coeff <- cor.test(dataset$time, dataset$mass)

# ~ +- 1 -> high correlation
cor_coeff$estimate

# 2.1
# a scatter plot can visually aid in the correlation determination
corrplot::corrplot(
    corr = cor(dataset),
    method = 'number'
)

ggplot(
    data = dataset,
    aes(
        x = `time`,
        y = `mass`
    )
) + geom_point(

) + geom_smooth(
    method = 'lm',
    se = FALSE
) + labs(

    x = 'Time in Second',
    y = 'Mass in Gram'
)

# 3
# create the Linear Regression Model
LR_Model <- lm(
    mass ~ time,
    data = dataset
)

summary(LR_Model)
