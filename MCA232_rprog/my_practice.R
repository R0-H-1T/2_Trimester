library(tidyverse)

data()

?BOD

head(BOD)

ggplot(BOD,
       aes(Time, demand)
       ) +
  geom_point() +
  geom_line()


head(CO2)
  
ggplot(
  CO2,
  aes(Plant, Type)
) + geom_point(
  
) + geom_line()
  
  
data(iris)
dim(iris)
summary(iris)
ggplot(
  iris,
  aes(
    Sepal.Length,
    Petal.Length,
    col = Species,
    shape = Species
  )
) + geom_point(
  col = "blue"
) + geom_smooth(
  col = "red"
)

data(mtcars)
names(mtcars)  
summary(mtcars)
dim(mtcars)
View(mtcars)
head(mtcars)
  
ggplot(
  mtcars,
  aes(
    gear,
  )
) + geom_bar() + coord_flip()
  
# plot a boxplot pmpg vs cyl
# cyl is categorical to we need to convert that to factor

ggplot(
  mtcars,
  aes(
    as.factor(cyl),
    mpg,
    
  )
) + geom_boxplot(
  
) + scale_color_manual(
  values = c("#3a0ca3", "#c9184a", "#3a5a40")
)

#violin plot
ggplot(
  mtcars,
  aes(
    as.factor(cyl),
    mpg,
  )
) + geom_violin( aes( fill = cyl ))


ggplot(
  mtcars,
  aes( mpg, 
       hp, 
       col = factor(cyl),
       shape = factor(am)
       )
) + geom_point(
  
) + labs ( 
  title = "Miles",
  x = "Horsepower",
  y = "Miles per gallon"
)


ggplot(
  iris,
  aes(
    Sepal.Length,
    fill = Species
  )
) + geom_histogram(
  
) + facet_wrap( ~Species)
  





  
