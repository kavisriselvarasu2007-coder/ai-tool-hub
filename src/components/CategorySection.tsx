import { type Category } from "@/data/aiTools";
import ToolCard from "./ToolCard";

type CategorySectionProps = {
  category: Category;
};

const CategorySection = ({ category }: CategorySectionProps) => {
  const Icon = category.icon;
  return (
    <section className="mb-16">
      <div className="flex items-center gap-3 mb-6">
        <div className="w-10 h-10 rounded-lg bg-accent/15 flex items-center justify-center">
          <Icon className="w-5 h-5 text-accent" />
        </div>
        <h2 className="font-display text-2xl font-bold text-foreground">{category.name}</h2>
        <span className="text-sm text-muted-foreground ml-auto">{category.tools.length} tools</span>
      </div>
      <div className="grid grid-cols-1 sm:grid-cols-2 lg:grid-cols-3 gap-4">
        {category.tools.map((tool, i) => (
          <ToolCard key={tool.name} tool={tool} index={i} />
        ))}
      </div>
    </section>
  );
};

export default CategorySection;
