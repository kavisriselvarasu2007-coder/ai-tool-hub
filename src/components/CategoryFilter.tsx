import { categories } from "@/data/aiTools";

type CategoryFilterProps = {
  selected: string | null;
  onSelect: (id: string | null) => void;
};

const CategoryFilter = ({ selected, onSelect }: CategoryFilterProps) => {
  return (
    <div className="flex flex-wrap gap-2 justify-center">
      <button
        onClick={() => onSelect(null)}
        className={`category-chip ${selected === null ? "category-chip-active" : "category-chip-inactive"}`}
      >
        All
      </button>
      {categories.map((cat) => (
        <button
          key={cat.id}
          onClick={() => onSelect(cat.id)}
          className={`category-chip ${selected === cat.id ? "category-chip-active" : "category-chip-inactive"}`}
        >
          {cat.name}
        </button>
      ))}
    </div>
  );
};

export default CategoryFilter;
