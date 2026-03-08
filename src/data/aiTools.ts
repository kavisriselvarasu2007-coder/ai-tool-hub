import {
  Youtube, PenTool, Twitter, Briefcase, Chrome, Video,
  Code, DollarSign, Mail, Zap, TrendingUp, Search,
  Film, Smile, Music, Image
} from "lucide-react";

export type Category = {
  id: string;
  name: string;
  icon: any;
  tools: Tool[];
};

export type Tool = {
  name: string;
  description: string;
};

export const categories: Category[] = [
  {
    id: "youtube", name: "YouTube Tools", icon: Youtube,
    tools: [
      { name: "TubeBuddy", description: "SEO & channel management for YouTube creators" },
      { name: "vidIQ", description: "YouTube analytics and keyword research tool" },
      { name: "Pictory", description: "Turn scripts into short branded videos" },
      { name: "Opus Clip", description: "AI-powered short clip generator from long videos" },
      { name: "Thumbnaily", description: "AI thumbnail generator for YouTube" },
      { name: "Gling", description: "Auto-edit YouTube videos, remove silences & bad takes" },
    ],
  },
  {
    id: "writing", name: "Writing Tools", icon: PenTool,
    tools: [
      { name: "Jasper", description: "AI writing assistant for marketing content" },
      { name: "Copy.ai", description: "Generate marketing copy in seconds" },
      { name: "Writesonic", description: "AI writer for blogs, ads, and product descriptions" },
      { name: "Rytr", description: "Affordable AI writing assistant" },
      { name: "Grammarly", description: "AI-powered grammar and style checker" },
      { name: "QuillBot", description: "Paraphrasing and summarization tool" },
    ],
  },
  {
    id: "twitter", name: "Twitter Tools", icon: Twitter,
    tools: [
      { name: "Typefully", description: "Write and schedule Twitter threads" },
      { name: "TweetHunter", description: "AI-powered tweet inspiration and scheduling" },
      { name: "Hypefury", description: "Grow your Twitter audience with AI" },
      { name: "Postwise", description: "AI ghostwriter for viral tweets" },
      { name: "Tribescaler", description: "Generate hooks for Twitter threads" },
      { name: "BlackMagic.so", description: "Twitter CRM and analytics dashboard" },
    ],
  },
  {
    id: "management", name: "Management Tools", icon: Briefcase,
    tools: [
      { name: "Notion AI", description: "AI-enhanced workspace for docs, tasks, wikis" },
      { name: "ClickUp AI", description: "Project management with AI writing & summarization" },
      { name: "Monday.com", description: "Work OS with AI-powered automations" },
      { name: "Reclaim.ai", description: "AI scheduling and time management" },
      { name: "Taskade", description: "AI-powered task and project management" },
      { name: "Mem.ai", description: "AI-powered self-organizing notes" },
    ],
  },
  {
    id: "chrome", name: "Chrome Extensions", icon: Chrome,
    tools: [
      { name: "AIPRM", description: "Curated ChatGPT prompt templates" },
      { name: "Merlin", description: "ChatGPT Plus on all websites" },
      { name: "Monica", description: "AI copilot in your browser" },
      { name: "Compose AI", description: "AI-powered autocompletion for emails" },
      { name: "Wiseone", description: "AI reading companion for complex articles" },
      { name: "Harpa AI", description: "AI agent for Chrome automation" },
    ],
  },
  {
    id: "content", name: "Content Creation", icon: Video,
    tools: [
      { name: "Canva AI", description: "Design with AI-powered tools and templates" },
      { name: "Descript", description: "AI video & podcast editing platform" },
      { name: "Synthesia", description: "Create AI videos with digital avatars" },
      { name: "Lumen5", description: "Turn blog posts into engaging videos" },
      { name: "Kapwing", description: "AI-powered collaborative video editor" },
      { name: "InVideo", description: "Create professional videos with AI" },
    ],
  },
  {
    id: "coding", name: "Coding Tools", icon: Code,
    tools: [
      { name: "GitHub Copilot", description: "AI pair programmer for code suggestions" },
      { name: "Cursor", description: "AI-first code editor" },
      { name: "Tabnine", description: "AI code completion for all languages" },
      { name: "Replit AI", description: "AI-powered collaborative coding platform" },
      { name: "Codeium", description: "Free AI code completion and chat" },
      { name: "Lovable", description: "AI full-stack web app builder" },
    ],
  },
  {
    id: "sales", name: "Sales Tools", icon: DollarSign,
    tools: [
      { name: "Gong", description: "Revenue intelligence with AI conversation analysis" },
      { name: "Apollo.io", description: "AI-powered lead gen and sales engagement" },
      { name: "Outreach", description: "AI-driven sales execution platform" },
      { name: "Seamless.AI", description: "Real-time contact data and lead building" },
      { name: "Lavender", description: "AI email coach for sales reps" },
      { name: "Regie.ai", description: "AI content platform for sales teams" },
    ],
  },
  {
    id: "email", name: "Email Marketing", icon: Mail,
    tools: [
      { name: "Mailchimp AI", description: "AI-powered email campaigns and automation" },
      { name: "Beehiiv", description: "Newsletter platform with AI writing tools" },
      { name: "Smartwriter", description: "AI cold email personalization" },
      { name: "Instantly", description: "AI-powered cold email outreach at scale" },
      { name: "Seventh Sense", description: "AI email delivery optimization" },
      { name: "Phrasee", description: "AI-generated email subject lines & copy" },
    ],
  },
  {
    id: "productivity", name: "Productivity", icon: Zap,
    tools: [
      { name: "Otter.ai", description: "AI meeting notes and transcription" },
      { name: "Fireflies.ai", description: "AI notetaker for meetings" },
      { name: "Bardeen", description: "AI-powered workflow automation" },
      { name: "Tldv", description: "Record, transcribe, and summarize meetings" },
      { name: "SaneBox", description: "AI email management and filtering" },
      { name: "Krisp", description: "AI noise cancellation for calls" },
    ],
  },
  {
    id: "marketing", name: "Marketing", icon: TrendingUp,
    tools: [
      { name: "HubSpot AI", description: "AI-powered CRM and marketing automation" },
      { name: "Persado", description: "AI-generated marketing language" },
      { name: "Albert.ai", description: "Autonomous AI marketing platform" },
      { name: "Anyword", description: "AI copywriting with predictive analytics" },
      { name: "Pathmatics", description: "AI digital ad intelligence" },
      { name: "Crayon", description: "AI competitive intelligence platform" },
    ],
  },
  {
    id: "seo", name: "SEO Tools", icon: Search,
    tools: [
      { name: "Surfer SEO", description: "AI-powered on-page SEO optimization" },
      { name: "Clearscope", description: "AI content optimization for SEO" },
      { name: "Frase", description: "AI SEO content research and writing" },
      { name: "MarketMuse", description: "AI content strategy and planning" },
      { name: "NeuronWriter", description: "SEO content editor with AI suggestions" },
      { name: "SE Ranking", description: "All-in-one SEO platform with AI features" },
    ],
  },
  {
    id: "video", name: "Video Editing", icon: Film,
    tools: [
      { name: "Runway", description: "AI-powered creative video editing suite" },
      { name: "HeyGen", description: "AI video generation with talking avatars" },
      { name: "Veed.io", description: "Online video editor with AI features" },
      { name: "Fliki", description: "Turn text into videos with AI voices" },
      { name: "Colossyan", description: "AI video creation for workplace learning" },
      { name: "Elai.io", description: "Text-to-video with AI presenters" },
    ],
  },
  {
    id: "daily", name: "Daily Life Tools", icon: Smile,
    tools: [
      { name: "ChatGPT", description: "Versatile AI assistant for any task" },
      { name: "Perplexity", description: "AI-powered search engine with citations" },
      { name: "Claude", description: "Thoughtful AI assistant by Anthropic" },
      { name: "Gemini", description: "Google's multimodal AI assistant" },
      { name: "Character.ai", description: "Chat with AI-generated characters" },
      { name: "Replika", description: "AI companion for conversation" },
    ],
  },
  {
    id: "music", name: "Music Tools", icon: Music,
    tools: [
      { name: "Suno", description: "Generate original songs with AI" },
      { name: "Udio", description: "AI music generation platform" },
      { name: "AIVA", description: "AI composer for emotional soundtrack music" },
      { name: "Soundraw", description: "AI music generator for creators" },
      { name: "Boomy", description: "Create original songs in seconds" },
      { name: "Mubert", description: "AI-generated royalty-free music" },
    ],
  },
  {
    id: "image", name: "Image Tools", icon: Image,
    tools: [
      { name: "Midjourney", description: "AI art generation from text prompts" },
      { name: "DALL·E 3", description: "OpenAI's advanced image generation" },
      { name: "Stable Diffusion", description: "Open-source AI image generation" },
      { name: "Leonardo.ai", description: "AI image generation for creative projects" },
      { name: "Remove.bg", description: "AI background removal in one click" },
      { name: "Photoroom", description: "AI photo editor for product images" },
    ],
  },
];
