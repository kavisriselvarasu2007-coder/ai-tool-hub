import { useState, useMemo } from "react";
import HeroSection from "@/components/HeroSection";
import SearchBar from "@/components/SearchBar";
import CategoryFilter from "@/components/CategoryFilter";
import CategorySection from "@/components/CategorySection";
import Footer from "@/components/Footer";
import { categories } from "@/data/aiTools";

const Index = () => {
  const [search, setSearch] = useState("");
  const [selectedCategory, setSelectedCategory] = useState<string | null>(null);

  const filtered = useMemo(() => {
    const q = search.toLowerCase();
    return categories
      .filter((cat) => !selectedCategory || cat.id === selectedCategory)
      .map((cat) => ({
        ...cat,
        tools: cat.tools.filter(
          (t) =>
            !q ||
            t.name.toLowerCase().includes(q) ||
            t.description.toLowerCase().includes(q) ||
            cat.name.toLowerCase().includes(q)
        ),
      }))
      .filter((cat) => cat.tools.length > 0);
  }, [search, selectedCategory]);

  return (
    <div className="min-h-screen bg-background">
      <HeroSection />
      <div className="container max-w-6xl mx-auto px-4 -mt-8 relative z-20">
        <div className="space-y-6 mb-16">
          <SearchBar value={search} onChange={setSearch} />
          <CategoryFilter selected={selectedCategory} onSelect={setSelectedCategory} />
        </div>
        <div className="text-sm text-muted-foreground mb-8">
          Showing {filtered.reduce((a, c) => a + c.tools.length, 0)} tools across {filtered.length} categories
        </div>
        {filtered.map((cat) => (
          <CategorySection key={cat.id} category={cat} />
        ))}
        {filtered.length === 0 && (
          <div className="text-center py-20 text-muted-foreground">
            <p className="text-lg">No tools found matching your search.</p>
          </div>
        )}
      </div>
      <Footer />
    </div>
  );
};

export default Index;
