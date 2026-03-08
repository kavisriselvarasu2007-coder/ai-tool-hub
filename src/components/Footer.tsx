import { Sparkles } from "lucide-react";

const Footer = () => (
  <footer className="border-t border-border/50 py-12 mt-20">
    <div className="container max-w-6xl mx-auto px-4 text-center">
      <div className="flex items-center justify-center gap-2 mb-4">
        <Sparkles className="w-5 h-5 text-primary" />
        <span className="font-display font-bold text-lg gradient-text">99 Best AI Tools</span>
      </div>
      <p className="text-muted-foreground text-sm max-w-md mx-auto">
        A curated collection of the most impactful AI tools in 2025. Updated regularly to keep you ahead of the curve.
      </p>
      <p className="text-muted-foreground/50 text-xs mt-6">© 2025 kavisriselvarasu. All rights reserved.</p>
    </div>
  </footer>
);

export default Footer;
