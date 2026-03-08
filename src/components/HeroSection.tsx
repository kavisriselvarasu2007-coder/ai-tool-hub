import { Sparkles, LogOut } from "lucide-react";
import { useNavigate } from "react-router-dom";
import { supabase } from "@/integrations/supabase/client";
import { Button } from "@/components/ui/button";
import heroBg from "@/assets/hero-bg.jpg";

const HeroSection = () => {
  const navigate = useNavigate();

  const handleLogout = async () => {
    await supabase.auth.signOut();
    navigate("/login");
  };

  return (
    <section className="relative min-h-[70vh] flex items-center justify-center overflow-hidden">
      <img
        src={heroBg}
        alt="AI Tools Background"
        className="absolute inset-0 w-full h-full object-cover opacity-40"
      />
      <div className="absolute inset-0 bg-gradient-to-b from-background/60 via-background/40 to-background" />
      <div className="relative z-10 text-center px-4 max-w-4xl mx-auto">
        <div className="inline-flex items-center gap-2 px-4 py-2 rounded-full glass-card glow-border mb-6 animate-fade-in">
          <Sparkles className="w-4 h-4 text-primary" />
          <span className="text-sm font-medium text-primary">Curated for 2025</span>
        </div>
        <h1 className="font-display text-5xl md:text-7xl font-bold mb-6 animate-fade-in" style={{ animationDelay: "0.1s" }}>
          <span className="gradient-text">99 Best AI Tools</span>
          <br />
          <span className="text-foreground">in 2025</span>
        </h1>
        <p
          className="text-lg md:text-xl text-muted-foreground max-w-2xl mx-auto animate-fade-in opacity-0"
          style={{ animationDelay: "0.25s" }}
        >
          Discover the most powerful AI tools across 16 categories — from coding and content creation to music and marketing.
        </p>
      </div>
    </section>
  );
};

export default HeroSection;
