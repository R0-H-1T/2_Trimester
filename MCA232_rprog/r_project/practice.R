toothdata = ToothGrowth
toothdata

library(ggplot2)

summary(toothdata)
str(toothdata)

toothdata

ggplot(
  data = toothdata,
  aes (x = `dose`)
) + geom_density() + facet_grid( ~`dose`)

ggplot(
  data = toothdata,
  aes(
    group = `dose`,
    x = `dose`,
    y = `len`,
    fill =factor(`dose`)  
  ) + boxplot()
)


#violin plot
ggplot(
  data = toothdata,
  aes(
    x = `dose`,
    y = 'len',
    fill = `dose`
  ) 
) + geom_boxplot()


#violin plot
ggplot(toothdata, aes(x = dose)) +
  geom_dotplot(method = "histdot", binwidth = 1.5)

toothdata

ggplot(toothdata, aes(x=dose, y=supp, fill=dose)) + geom_violin()
  