library(ggplot2)

View(ToothGrowth)

tooth_growth = ToothGrowth

summary(tooth_growth)

# Construct a plot showing the density of three dose level independently
ggplot(
  data = tooth_growth,
  aes(    x = `dose`  )
) + geom_density(
  
) + facet_grid(  ~`dose`)

# Draw a violin plot to understand how tooth growth is affected by either factor.
ggplot(
  data = tooth_growth,
  aes(    y = `len`,    x = `dose`,    fill = `supp`  )
) + geom_violin(
) + facet_grid(
  ~`supp`
) + scale_fill_brewer(  direction = -1
) + labs(  x = "Dose",  y = "Tooth Length",  fill = "Supplement"
) + theme_minimal()

# Create a plot as shown below.
ggplot(
  data = tooth_growth,
  aes(    group = `dose`,    x = `dose`,    y = `len`,    fill = factor(`dose`)  )
) + geom_boxplot(
  
) + facet_grid(
  ~`supp`,
  labeller = labeller(
    supp = c("Orange Juice", "Vitamin C")
  )
) + labs(
  x = "Dose in milligrams/day",
  y = "Tooth length",
  title = "Tooth length vs. Dose length",
  subtitle = "Comparison by supplement type",
  fill = "dose",
)

# Create a plot as shown below (Hint: geom_dotplot)
ggplot(
  data = tooth_growth,
  aes(
    x = `len`,
    fill = factor(`dose`)
  )
  
) + geom_dotplot(
  
) + labs(
  fill = "dose"
)


# Plot the correlation of Toothgrowth dataset using any package.
ggplot(
  data = tooth_growth,
  aes(    x = `dose`,    y = `len`,    color = `supp`  )
) + geom_point(
  
) + scale_color_brewer(
  
) + labs(
  title = "Dose vs. Tooth Length",
  x = "Dose",
  y = "Tooth Length",
  color = "Supplement",
)
